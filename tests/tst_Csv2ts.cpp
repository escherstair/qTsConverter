#include "tst_Csv2ts.hpp"

#include "../src/Csv2TsConverter.hpp"

void tst_Csv2ts::cleanup()
{
    QFile::remove(m_outputFile.c_str());
}

void tst_Csv2ts::checkScenario1()
{
    const auto inputFile{ FILESPATH + std::string("/scenario1.csv") };
    Csv2TsConverter converter(inputFile, FILESPATH, ";", "\"");
    converter.process();
    QFile output(m_outputFile.c_str());
    QVERIFY(output.exists());

    QFile expected(FILESPATH + QString("/scenario1.ts"));
    expected.open(QIODevice::ReadOnly);
    output.open(QIODevice::ReadOnly);

    const auto o = output.readAll();
    const auto e = expected.readAll();

    QCOMPARE(o.size(), e.size());
    QCOMPARE(o, e);
}