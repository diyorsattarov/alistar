# Contributing to Alistar

First off, thank you for considering contributing to Alistar! It's people like you that make Alistar such a great tool.

## Code of Conduct

By participating in this project, you agree to abide by our [Code of Conduct](CODE_OF_CONDUCT.md).

## How Can I Contribute?

### Reporting Bugs

1. **Check Existing Issues** - Check if the bug has already been reported.
2. **Create an Issue** - If not already reported, create a new issue:
   - Use a clear and descriptive title
   - Describe the exact steps to reproduce the problem
   - Provide specific examples
   - Include compiler version and platform information

### Suggesting Enhancements

1. **Create an Issue** for your enhancement suggestion
2. **Describe Your Enhancement** in detail:
   - Why this enhancement would be useful
   - How it should work
   - Include code examples if applicable

### Pull Requests

1. **Fork the Repository**
2. **Create a Branch** (`git checkout -b feature/AmazingFeature`)
3. **Make Changes** following our coding standards
4. **Add Tests** for any new functionality
5. **Run Tests** (`cmake --build build`)
6. **Commit Changes** (`git commit -m 'Add some AmazingFeature'`)
7. **Push to Branch** (`git push origin feature/AmazingFeature`)
8. **Open a Pull Request**

## Coding Standards

- Use C++17 features appropriately
- Follow existing code formatting
- Include documentation for new functions/classes
- Add tests for new functionality
- Keep commits atomic and messages clear

## Testing

Before submitting a PR:
```cpp
// Example test
tst_suite<int> suite;
suite.add("Your New Feature Test", []() {
    // Your test code here
});
suite.run();
```

## Documentation

- Comment your code
- Update relevant wiki pages
- Add examples for new features

## Questions?

Feel free to create an issue labeled 'question' or contact the maintainers.

Thank you for your contributions!

