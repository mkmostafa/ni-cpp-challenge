#include <NI.h>

template <>
std::string NI<char>::getNi() {
	return "Ni";
}

template <>
std::wstring NI<wchar_t>::getNi() {
	return L"Ni";
}

template <>
std::string NI<char>::getNI() {
	return "NI";
}

template <>
std::wstring NI<wchar_t>::getNI() {
	return L"NI";
}

template <>
std::size_t NI<wchar_t>::len() {
	return std::wcslen(_str);
}

template <>
std::size_t NI<char>::len() {
	return std::strlen(_str);
}