#include "WindowsMessageMap.h"

#define registermsg( msg ) {msg,#msg}

WindowsMessageMap::WindowsMessageMap():
	map({ registermsg( WM_GETMINMAXINFO ),
		 registermsg(WM_NCCREATE),
		 registermsg(WM_NCCALCSIZE),
		 registermsg(WM_CREATE),
		 registermsg(WM_SHOWWINDOW),

		 registermsg(WM_GETICON),
		 registermsg(WM_NCACTIVATE),
		 registermsg(WM_SETCURSOR),
		 registermsg(WM_MOUSEMOVE),

		 registermsg(WM_NCHITTEST),
		 registermsg(WM_MOVING),
		 registermsg(WM_MOVE),
		 registermsg(WM_WINDOWPOSCHANGED),

		 registermsg(WM_WINDOWPOSCHANGING),
		 registermsg(WM_NCMOUSEMOVE),
		 registermsg(WM_NCMOUSELEAVE),
		 registermsg(WM_CHAR),

		 registermsg(WM_KEYDOWN),
		 registermsg(WM_KEYUP),
					})
{ }

std::wstring WindowsMessageMap::operator()(DWORD msg,LPARAM lp,WPARAM wp) {
	constexpr int firstclowidth = 25;
	const auto i = map.find(msg);
	std::ostringstream oss;
	if (i != map.end()) {
		oss << std::left << std::setw(firstclowidth) << i->second;
	}
	else {
		//i==map.end(),no such msg
		std::ostringstream temposs;
		temposs << "Unkownmessage0x" << std::hex << msg;
		oss << std::left << std::setw(firstclowidth) << temposs.str();
	}
	//lp and wp
	oss << "LP:0x" << std::right<<std::setw(8)<<std::setfill('0') << std::hex << lp;
	oss << "  WP:0x" <<std::right<< std::setw(8) << std::setfill('0') << std::hex << wp<<std::endl;

	std::string temps = oss.str();
	std::wstring temp(temps.begin(), temps.end());
	

	return temp;
}