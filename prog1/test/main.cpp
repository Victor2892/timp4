#include <UnitTest++/UnitTest++.h>
#include "/home/student/TIMPLab/2laba/1/modAlphaCipher.h"
#include "/home/student/TIMPLab/2laba/1/modAlphaCipher.cpp"
SUITE(TestKey) 
{
    TEST(SmallRussianLetters) {
        modAlphaCipher t(L"пррпочя");
        CHECK(true);
    }
    TEST(BigRussianLetters) {
        modAlphaCipher t(L"ВЫЫЫЫЫЫФ");
        CHECK(true);
    }
    TEST(BigSmallRussianLetters) {
        modAlphaCipher t(L"выфвыфВЫФВЫФВ");
        CHECK(true);
    }
    TEST(InvalidCharactersNumber) {
        CHECK_THROW(modAlphaCipher t(L"РФ12"),Error);
    }
    TEST(InvalidCharactersSpecialCharacter) {
        CHECK_THROW(modAlphaCipher t(L"РЯЧС;()"),Error);
    }
    TEST(EmptyKey) {
        CHECK_THROW(modAlphaCipher t(L""), Error);
    }
}

struct Key_fixture { 
    modAlphaCipher * p;
    Key_fixture()
    {
        p = new modAlphaCipher(L"АВГД");
    }
    ~Key_fixture()
    {
        delete p;
    }
};

SUITE(TestEnc) 
{
    TEST_FIXTURE(Key_fixture, SmallRussianLetters) {
        wstring test = L"лабатри";
        CHECK_EQUAL(true, L"ЛВДДТТЛ" == p->encrypt(test));
    }
    TEST_FIXTURE(Key_fixture, BigRussianLetters) {
        wstring test = L"ТЕСТИРОВАНИЕ";
        CHECK_EQUAL(true, L"ТЖФЦИТСЁАПЛИ" == p->encrypt(test));
    }
    TEST_FIXTURE(Key_fixture, BigSmallRussianLetters) {
        wstring test = L"ВикторМещеряков";
        CHECK_EQUAL(true, L"ВКНЦОТПИЩЖУГКРЕ" == p->encrypt(test));
    }

    TEST_FIXTURE(Key_fixture, InvalidCharactersNumber) {
        wstring test = L"00Л";
        CHECK_THROW(p->encrypt(test),Error);
    }
    TEST_FIXTURE(Key_fixture, InvalidCharactersSpace) {
        wstring test = L"KKK Л";
        CHECK_THROW(p->encrypt(test),Error);
    }
    TEST_FIXTURE(Key_fixture,InvalidCharactersSpecialCharacter) {
        wstring test = L"Л :Л";
        CHECK_THROW(p->encrypt(test),Error);
    }
    TEST_FIXTURE(Key_fixture, EmptyText) {
        wstring test = L"";
        CHECK_THROW(p->encrypt(test),Error);
    }

}
SUITE(TestDec)
{
   TEST_FIXTURE(Key_fixture, SmallRussianLetters) {
        wstring test = L"лвддттл";
        CHECK_EQUAL(true, L"ЛАБАТРИ" == p->decrypt(test));
    }
    TEST_FIXTURE(Key_fixture, BigRussianLetters) {
        wstring test = L"ТЖФЦИТСЁАПЛИ";
        CHECK_EQUAL(true, L"ТЕСТИРОВАНИЕ" == p->decrypt(test));
    }
    TEST_FIXTURE(Key_fixture, SmallBigRussianLetters) {
        wstring test = L"ЛВдДПРхммС";
        CHECK_EQUAL(true, L"ЛАБАПОТИМП" == p->decrypt(test));
    }

    TEST_FIXTURE(Key_fixture,InvalidCharactersNumber) {
        wstring test = L"УУУУ999А";
        CHECK_THROW(p->decrypt(test),Error);
    }
     TEST_FIXTURE(Key_fixture,InvalidCharactersSpace) {
        wstring test = L"ВЫФВ ВЫВФ";
        CHECK_THROW(p->decrypt(test),Error);
    }
    
    TEST_FIXTURE(Key_fixture,InvalidCharactersSpecialCharacter) {
        wstring test = L"РРРР***(";
        CHECK_THROW(p->decrypt(test),Error);
    }
   
    TEST_FIXTURE(Key_fixture, EmptyText) {
        wstring test = L"";
        CHECK_THROW(p->decrypt(test),Error);
    }
    
}
int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
