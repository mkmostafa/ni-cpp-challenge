#ifndef _NI_H_
#define _NI_H_

#include <type_traits>
#include <string>
#include <functional>
#include <iostream>

/* 
	the second template parameter is to allow instantiation 
	of the class with only w_char* and char*
*/
template <typename CharType, 
		  typename std::enable_if<std::is_same <CharType, wchar_t>::value || 
								  std::is_same <CharType, char>::value, int
								  >::type* = nullptr
		  >
class MyClass {
private:
	/* 
		typedef wstring StringType if w_char is template parameter
		typedef string StringType if char is template parameter
	*/
	typedef typename std::conditional<std::is_same<CharType, wchar_t>::value, 
									 std::wstring, 
									 typename std::conditional<std::is_same<CharType, char>::value, 
											  				   std::string, 
											  				   void>::type
								 	>::type StringType;

	const CharType* _str;
	
	StringType getNi();
	StringType getNI();
	std::size_t len();

	// search for Ni and execute f on every match
	void searchForNi(const std::function<void(std::size_t)>& f) {
		const StringType& Ni = getNi();
		if(Ni.size() > len()) {
			return;
		}

		for(std::size_t i = 0; i <= len() - Ni.size(); i++) {
			bool match = true;
			for(std::size_t j = 0; j < Ni.size(); j++) {
				if(Ni[j] != _str[i + j]) {
					match = false;
					break;
				}
			}
			if(match) {
				f(i);
			}
		}
	}

public:
	NI(const CharType* str) : _str(str) {}

	std::size_t getNiCount() {
		std::size_t NiCount = 0;
		
		const auto& increment = [&NiCount](std::size_t i) -> void {
			NiCount++;
		};

		searchForNi(increment);

		return NiCount;
	}

	StringType replaceNiWithNI() {
		StringType ret(_str);
		const StringType& NI = getNI();

		const auto& replace = [&ret, &NI](std::size_t i) -> void {
			ret[i] = NI[0];
			ret[i + 1] = NI[1];
		};

		searchForNi(replace);

		return ret;
	}
};

#endif