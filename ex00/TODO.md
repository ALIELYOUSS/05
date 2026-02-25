# Exercise 00: Mommy, when I grow up, I want to be a Bureaucrat!

## Topic: Exceptions

## Goal
Create a `Bureaucrat` class with exception handling.

## Requirements
- [x] **Bureaucrat class** with:
  - `const std::string name`
  - `int grade` (range: 1 highest, 150 lowest)
- [ ] **Orthodox Canonical Form** (default constructor, copy constructor, copy assignment, destructor)
  - [x] Default constructor — declared & defined (but doesn't init members)
  - [ ] Copy constructor — **MISSING** (declared with typo `bureacrat`, not implemented)
  - [ ] Copy assignment operator — **HAS BUGS**: `other->grade` should be `other.grade`, `return this` should be `return *this`
  - [x] Destructor — done
- [ ] **Getters**: `getName()`, `getGrade()`
  - [ ] Declared with syntax errors: `getName(); const;` → remove extra `;`
- [ ] **Member functions**:
  - [ ] `incrementGrade()` — **BUG**: uses `throw new` (should throw by value, not pointer)
  - [ ] `decrementGrade()` — **BUGS**: uses `throw new`, typo `GradetooHighException` should be `GradeTooLowException`
- [ ] **Exceptions**:
  - [ ] `Bureaucrat::GradeTooHighException` — **must be nested** inside Bureaucrat class (currently outside)
  - [ ] `Bureaucrat::GradeTooLowException` — **must be nested** inside Bureaucrat class (currently outside)
  - [ ] Both have typo `exeption` → `exception`, missing `;` after `}`, missing `throw()` on `what()`
  - [ ] Implementations in .cpp are broken: duplicated, use `virtual` keyword, no class scope
- [ ] **Overload** `<<` operator to print: `<name>, Bureaucrat grade <grade>.` — **NOT IMPLEMENTED**
- [ ] **Constructor taking name + grade** — **MISSING** (only have name-only constructor)
- [ ] Write a `main.cpp` with tests (try/catch blocks) — **current main tests unrelated `obj` class, not Bureaucrat**
- [ ] Create a `Makefile` (NAME, all, clean, fclean, re) — **EMPTY**

## Files to create
- [ ] Makefile — exists but empty
- [x] main.cpp — exists but needs rewrite
- [x] Bureaucrat.hpp — exists but has many bugs (see above)
- [x] Bureaucrat.cpp — exists but has many bugs (see above)

## Bugs summary (fix in order)

### Bureaucrat.hpp
1. Move `GradeTooHighException` and `GradeTooLowException` **inside** `Bureaucrat` class as nested classes
2. Fix `exeption` → `exception`
3. Add `;` after each class closing brace `}`
4. Fix copy constructor param: `const bureacrat&` → `const Bureaucrat&`
5. Fix getter declarations: `getName(); const;` → `getName() const;` (same for `getGrade`)
6. Add `Bureaucrat(const std::string& name, int grade);` constructor
7. Add `friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);`
8. Add `throw()` to `what()` overrides

### Bureaucrat.cpp
1. Fix copy assignment: `other->grade` → `other.grade`, `return this` → `return *this`
2. Fix `throw new XException(...)` → `throw XException()` (no `new`, no args)
3. Fix `GradetooHighException` → `GradeTooLowException` in `decrementGrade()`
4. Add copy constructor implementation
5. Add `Bureaucrat(name, grade)` constructor with initializer list + grade validation
6. Rewrite exception `what()` implementations with proper class scope
7. Add `operator<<` implementation

### main.cpp
1. Replace `obj` test class with proper Bureaucrat tests using try/catch

### Makefile
1. Write full Makefile with NAME, CXX, CXXFLAGS, SRCS, all, clean, fclean, re















<!-- 
#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include <iostream> 
#include <exception>

class Bureaucrat{
private:
    const std::string name;
    int grade;
public:
    class GradeTooHighException : public exeption{
       public:
            virtual const char* what() const;
    }
    class GradeTooLowException : public exeption{
        public:
            virtual const char* what() const;
    }
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);
    Bureaucrat(const Bureaucrat& other);
    const std::string getName(); const;
    int         getGrade(); const;
    void    incrementGrade();
    void    decrementGrade();
}

#endif -->