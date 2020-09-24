// sv_txt Andreas Törnkvist 2020-09-23 CNG

#include <iostream>
#include <string>

const std::string sv_txt_bokstaver[6] = { "å", "ä", "ö", "Å", "Ä", "Ö" };
const std::string sv_txt_replace[6] = { "\x86", "\x84", "\x94", "\x8F", "\x8E", "\x99" };

std::string sv_txt(const std::string text) {
    //Lite kod som gör det möjligt att skriva ut åäö i windows-consolen
    //Andreas Törnkvist 2020-09-23 CNG
    std::string out;
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < 6; j++) {
            if (sv_txt_bokstaver[j][0] == text[i]) {
                out.append(sv_txt_replace[j]);
            }
        }
        if (i+1 > out.length()) {
            out.push_back(text[i]);
        }
    }
    return(out);
}

int main()
{
    std::cout << "Utan swe_txt: Åker båt öster om Öland!\n";
    std::cout << sv_txt("Med swe_txt: Åker båt öster om Öland!\n");
}
