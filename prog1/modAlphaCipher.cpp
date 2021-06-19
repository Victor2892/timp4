#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(const wstring& skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(getValidKey(skey));
}
wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    vector<int> work = convert(getValidOpenCipherText(open_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    vector<int> work = convert(getValidOpenCipherText(cipher_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

inline vector<int> modAlphaCipher::convert(const wstring& s)
{
    vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}

inline wstring modAlphaCipher::convert(const vector<int>& v)
{
    wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
inline wstring modAlphaCipher::getValidKey(const wstring & ws)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring tmp = ws;
    if (tmp.empty())
        throw Error("вы указали пустой ключ.");
    for (auto & el : tmp) {
         if (!iswalpha(el))
            throw Error("в вашем ключе присутствуют недопустимые символы.");
        if (iswlower(el))
            el = towupper(el);
    }
    return tmp;
}
inline wstring modAlphaCipher::getValidOpenCipherText(const wstring & ws)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring tmp = ws;
    if (tmp.empty())
        throw Error("вы указали пустую строку.");
    for (auto & el : tmp) {
         if (!iswalpha(el))
            throw Error("в вашей строке присутствуют недопустимые символы.");
        if (iswlower(el))
            el = towupper(el);
    }
    return tmp;
}
