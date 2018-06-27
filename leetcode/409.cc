#include<string>
#include<iostream>
using namespace std;
int longestPalindrome(string s) {
        int length = s.length();
        if(length == 0)
            return 0;
        int map[256] = {0};
        std::cout << length << std::endl;
        for(int i=0;i<s.length();i++) 
            ++map[s[i]];
        for(uint8_t i=0;i<128;i++) {
            std::cout << (char)i << ": " << map[i] << std::endl;
        }
        int res = 0;
        for(int i=0;i<256;i++) {
            if(map[i]>0 && map[i]%2==0)
                res += map[i];
            if(map[i]%2==1)
                res += map[i]-1;
        }
        return res+1;
    }

int main()
{
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    std::cout << longestPalindrome(s) << std::endl;;
}
