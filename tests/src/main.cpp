#include <vector>
#include <string>
#include "tests.h"
#include "TestReporterStdout.h"


/// @mainpage
///
/// @section id1 Spu�t�n� vybran�ho testu
///
/// Spu�t�n� vybran�ho testu: "area_test.exe Test1 Test2" spust� vybran� testy,
/// "area_test.exe suite Suite1 Suite2" spust� vybran� suite.
///
/// V project "Properties/Build Events/Post-build event/Use in build"
/// lze zapnout nebo vypnout spu�t�n� testu po kompilaci.


int main(int argc, char * argv[])
{
	if (argc > 1) {
		std::vector<std::string> arguments;
		arguments.assign(argv + 1, argv + argc);

		// Pokud je prvn� argument "suite", hled�me v seznamu v�ech suite
		const bool isSuite = (arguments[0] == "suite");

		// Projdi seznam test� a p�idej ty, jejich� jm�na se shoduj�
		const UnitTest::TestList & allTests(UnitTest::Test::GetTestList());
		UnitTest::TestList selectedTests;
		UnitTest::Test * test = allTests.GetHead();
		while (test) {
			for (size_t i = 0; i < arguments.size(); ++i) {
				if (isSuite && arguments[i] == test->m_details.suiteName) {
					selectedTests.Add(test);
				}
				else if (!isSuite && arguments[i] == test->m_details.testName) {
					selectedTests.Add(test);
				}
			}
			test = test->m_nextTest;
		}

		// Spus� jen vybran� testy
		UnitTest::TestReporterStdout reporter;
		UnitTest::TestRunner runner(reporter);
		selectedTests.Add(0); // Pravd�podobn� bug. Nutno p�idat, aby se nespustily v�echny dal�� testy.
		return runner.RunTestsIf(selectedTests, 0, UnitTest::True(), 0);
	}
	else {
		// Spus� v�echny testy
		return UnitTest::RunAllTests();
	}
}
