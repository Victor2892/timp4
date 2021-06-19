#include <UnitTest++/UnitTest++.h>
#include "/home/student/TIMPLab/2laba/2/Cipher.h"
#include "/home/student/TIMPLab/2laba/2/Cipher.cpp"

SUITE(TestKey) 
{
    TEST(Correct) {
        Cipher t("5");
        CHECK(true);
    }
    TEST(NegativeNumber) {
        CHECK_THROW(Cipher t("-7"), CipherError);
    }
    TEST(Text) {
       CHECK_THROW(Cipher t("TEXT текст"), CipherError);
    }
    TEST(EmptyKey) {
        CHECK_THROW(Cipher t(""), CipherError);
    }
}

Cipher key ("4");
SUITE(TestEnc)
{
    TEST(Russianletters) {
        wstring test = L"ВикторМещеряковА";
        CHECK_EQUAL(true, L"ВощкиреокМрвтеяА" == key.encrypt(test));
    }
    TEST(Englishletters) {
        wstring test = L"vsemPRiVETTT";
        CHECK_EQUAL(true, L"vPEsRTeiTmVT" == key.encrypt(test));
    }
    TEST(SpecialCharacters) {
        wstring test = L"&*(@#)_-";
        CHECK_EQUAL(true, L"&#*)(_@-" == key.encrypt(test));
    }
    TEST(NumbersCharacters) {
        wstring test = L"0123456789";
        CHECK_EQUAL(true, L"04815926 37" == key.encrypt(test));
    }
    TEST(SpaceCharacters) {
        wstring test = L"ura u ra";
        CHECK_EQUAL(true, L"uur ar a" == key.encrypt(test));
    }
    TEST(AllCharacters) {
        wstring test = L"hello world Ура12* (";
        CHECK_EQUAL(true, L"horУ2e lр*lwdа lo 1(" == key.encrypt(test));
    }
    TEST(EmptyText) {
        wstring test = L"";
        CHECK_THROW(key.encrypt(test), CipherError);
    }
}

SUITE(TestDec)
{
    TEST(Russianletters) {
        wstring test = L"ВощкиреокМрвтеяА";
        CHECK_EQUAL(true, L"ВикторМещеряковА" == key.decrypt(test));
    }
    TEST(Englishletters) {
        wstring test = L"vPEsRTeiTmVT"; 
        CHECK_EQUAL(true, L"vsemPRiVETTT" == key.decrypt(test));
    }
    TEST(SpecialCharacters) {
        wstring test = L"(*)?+:=%";
        CHECK_EQUAL(true, L"()+=*?:%" == key.decrypt(test));
    }
    TEST(NumbersCharacters) {
        wstring test = L"9876543210";
        CHECK_EQUAL(true, L"9630852 74" == key.decrypt(test));
    }
    TEST(SpaceCharacters) {
        wstring test = L"uur ar a";
        CHECK_EQUAL(true, L"ura u ra" == key.decrypt(test));
    }
    TEST(AllCharacters) {
        wstring test = L"hoрe  LМ1Lи!";
        CHECK_EQUAL(true, L"heLLo Мир 1!" == key.decrypt(test));
    }
    TEST(EmptyText) {
        wstring test = L"";
        CHECK_THROW(key.decrypt(test), CipherError);
    }
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
