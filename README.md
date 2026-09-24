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

###How to use

This library contains hardware level interfaces that must be implemented in your project to use the concrete classes for odometry, localization etc. The Core folder contains interfaces for motors, motorgroups and chassis.
After implementing a concrete motor class, create motor groups. Then, you can either use one of the drivetrain concrete classes provided or write your own. 
