# Mobile Robot Library

A platform agnostic mobile robot library for use in wheeled mobile robots. Contains interfaces for odometry, localizers, control algorithms, trajectory file parsing, and path following. 

### Prerequisites

None

### Setup

Clone the repository:

git@github.com:Aiden-Wang44/Mobile-Robot-Library.git

Or:

git submodule add git@github.com:Aiden-Wang44/Mobile-Robot-Library.git "path/to/folder"

git add .gitmodules "path/to/folder"

git commit -m "added submodule"

git push origin main

### How to use

This library contains hardware level interfaces that must be implemented in your project to use the concrete classes for odometry, localization etc. The Core folder contains interfaces for motors, motorgroups and chassis.

1. Implement a concrete motor class for your platform
2. Create relevant motor groups
3. Either create an object of the provided drivetrain classes, or write one.
