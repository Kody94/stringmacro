#include <QCoreApplication>
#include <iostream>

#define WHATS(F) \
	F(eWhatPrint) \
	F(eWhatPrintPass) \
	F(eWhatPrintData)

#define AS_ENUM(E) E,

enum class Whats {
	eWhatPrint,
	eWhatPrintPass,
	eWhatPrintData,
};

#define AS_STRING_CASE(E) \
	case Whats::E: \
		return #E;

constexpr char const *to_string(Whats const eWhat)
{
	switch (eWhat) {
	default:
		return nullptr;
		WHATS(AS_STRING_CASE)
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	std::cout << to_string(Whats::eWhatPrint) << "\n";
	std::cout << to_string(Whats::eWhatPrintPass) << "\n";
	std::cout << to_string(Whats::eWhatPrintData) << "\n";
}
