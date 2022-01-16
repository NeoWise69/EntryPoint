# EntryPoint
Simple and useful entry point for your application with care about command line arguments

#### How To Use? ####
Just include **BSEntry** both *.h and *.cpp files, and now you can delete your old boring *int main() blah-blah-blah*

#### Also... ####
You may just to include header file only and call both BSStart() and BSExit() functions inside of your startup file, just with replacing old 
```
int main(int argc, char* argv[])
{
``` 
with new 
```
void BSStart(const BSEntryArgs& args) noexcept
{

//
// Your code here...
//

void BSExit(int& code) noexcept
{
```

### Don't Forget!!!
At the end of your source file, you **must** define "BSEntryDecl()" for this to work.
