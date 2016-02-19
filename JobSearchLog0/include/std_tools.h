#ifndef STD_TOOLS_H_INCLUDED
#define STD_TOOLS_H_INCLUDED
#include <string>
#include <locale>
namespace std_tools {
    //! std::string s;
    //! tolower(s.begin(), s.end());
    template < typename ForwardIterator >
    ForwardIterator makelower(ForwardIterator first, ForwardIterator last, const std::locale& locale_ref = std::locale())
    {
        for(; first!=last; ++first) *first = std::tolower(*first, locale_ref);
        return first;
    }

    //! std::string s;
    //! makelower(s);
    template < typename CharT, typename Traits, typename Alloc >
    std::basic_string<CharT, Traits, Alloc>& makelower(std::basic_string<CharT, Traits, Alloc>& s, const std::locale& locale_ref = std::locale())
    {
        makelower(s.begin(), s.end(), locale_ref);
        return s;
    }

    //! std::string s1, s2;
    //! s2 = tolower(s1);
    template < typename CharT, typename Traits, typename Alloc >
    std::basic_string<CharT, Traits, Alloc> /*by value*/ tolower(std::basic_string<CharT, Traits, Alloc> /*by value*/ s, const std::locale& locale_ref = std::locale())
    {
        makelower(s.begin(), s.end(), locale_ref);
        return s;
    }

    //! std::string s = tolower("CASE");
    template < typename CharT >
    std::basic_string<CharT> /*by value*/ tolower(CharT const* s, const std::locale& locale_ref = std::locale())
    {
        return makelower(std::basic_string<CharT>(s), locale_ref);
    }
};
    // namespace std_tools - See more at: http://compgroups.net/comp.lang.c++.moderated/a-shot-at-tolower-std-basic_string/376766#sthash.jbN4gjFW.dpuf


#endif // STD_TOOLS_H_INCLUDED
