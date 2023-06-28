#include "ScoreManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>

ScoreManager::ScoreManager()
{
	m_Num = 5;
	m_currentScore = 0;
	printScores();
}

void ScoreManager::setCurrentScore(int s)
{
	m_currentScore = s;
}

int ScoreManager::getCurrentScore()
{
	return m_currentScore;
}

void ScoreManager::UpdateHighScore()
{
	int s = m_currentScore;
	for (int i = 0; i < m_Num; i++) {
		if (s > m_HighScore[i]) {
			std::swap(s, m_HighScore[i]);
		}
	}
	std::sort(m_HighScore, m_HighScore + m_Num, [](int a, int b) { return a > b; });
}

int ScoreManager::getBestScore()
{
	return m_HighScore[0];
}

void ScoreManager::readFile()
{
	//	std::fstream input;
	//	input.open("Score.data", std::ios::binary | std::ios::in);
	//	input.read((char*)m_HighScore, sizeof(m_HighScore));
	//	input.close();
	std::fstream input;
	input.open("Score.txt", std::ios::in);
	input >> m_HighScore[0] >> m_HighScore[1] >> m_HighScore[2] >> m_HighScore[3] >> m_HighScore[4];
	input.close();
}

void ScoreManager::writeFile()
{
	//	std::fstream output;
	//	output.open("Score.txt", std::ios::binary | std::ios::out);
	//	output.write((char*)m_HighScore, sizeof(m_HighScore));
	//	output.close();
	std::fstream output;
	output.open("Score.txt", std::ios::out);
	output << m_HighScore[0] << " " << m_HighScore[1] << " " << m_HighScore[2] << " " << m_HighScore[3] << " " << m_HighScore[4];
	output.close();
}

int* ScoreManager::getHighScore()
{
	return m_HighScore;
}

int ScoreManager::getNum()
{
	return m_Num;
}

void ScoreManager::printScores()
{
	for (int i = 0; i < m_Num; i++) {
		printf("%d ", m_HighScore[i]);
	}
	printf("\n");
}
