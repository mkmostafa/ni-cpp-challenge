#include <NI.h>

int main()
{
	const char* szTestString1 = "Ni nI NI nI Ni";
	NI<char> Ni1(szTestString1);
	std::cout << szTestString1 << ": " << std::endl;
	std::cout << "Found " <<  Ni1.getNiCount() << " occurrences of Ni. New string: " << Ni1.replaceNiWithNI() << std::endl;

	const wchar_t *szTestString2 = L"Ni nI NI nI Ni";
	NI<wchar_t> Ni2(szTestString2);
	std::wcout << szTestString2 << ": " << std::endl;
	std::wcout << "Found " <<  Ni2.getNiCount() << " occurrences of Ni. New string: " << Ni2.replaceNiWithNI() << std::endl;
}