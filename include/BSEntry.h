#if !(defined BS_ENTRY_H)
#define BS_ENTRY_H

// Handle startup command line arguments
struct BSEntryArgs {
    // Number of all arguments
	int		Count = 0;
    // Array of arguments of (char*)
	char** Args = 0;

	BSEntryArgs(int argc, char** argv) noexcept
		: Count(argc), Args(argv) {}

    // Access operator square brackets
	char* operator[](int pos) const {
		return Args[pos];
	}

    // Access function with bounds checking
	char* at(int pos) const {
		if (pos >= Count || pos == -1)
			return (char*)("BSEntryArgs - out of range");
		return Args[pos];
	}

};

#define __BS_CODE(v) { code = v; }

// Here below you can define your own exit codes by given construct
#define BS_EXIT_SUCCESS			__BS_CODE(0)
#define BS_EXIT_FAILED			__BS_CODE(-1)
#define BS_EXIT_POSTCODE(val)	__BS_CODE(val)

// The entry function itself, including the entry arguments
void BSStart(const BSEntryArgs& args) noexcept;

// Exit function for which you can define your own exit code
void BSExit(int& code) noexcept;

// Macro that overrides the standard "main" function
#if !(defined BSEntryDecl)
#define BSEntryDecl()				\
int main(int argc, char* argv[])	\
{									\
	BSStart({argc, argv});			\
	int exit_code = 0;				\
	BSExit(exit_code);				\
	return exit_code;				\
}
#endif // !BSEntryDecl()

#endif // !BS_ENTRY_H