#pragma once
#include<Windows.h>
#include<string>
#include<sstream>
#include<unordered_map>
#include<iostream>
#include<iomanip>

class WindowsMessageMap
{
	public:
		WindowsMessageMap();
		std::wstring operator()(DWORD msg,LPARAM lp,WPARAM wp);
	private:
		std::unordered_map<DWORD, std::string> map;
};

