This project is a small console-based C++ app that helps manage mechanical CAD parts like pipes, valves, elbows, and flanges.
You can add, view, search, and delete parts. 
The goal was to show clean design and use of modern C++ features.

Design Summary:-

The system is built around a base class called Part, which stores the common details of any CAD part (ID, name, material, diameter).
Specific parts like Pipe, Valve, Elbow, and Flange are created as derived classes, each adding their own properties.
Function overriding is used so the program knows how to print or identify each part correctly, even when handling them through base-class pointers.
All objects are stored using smart pointers, which automatically manage memory and prevent leaks.
A reusable template Repository class stores and manages all parts. It uses STL algorithms like find_if and remove_if for efficient operations.
Operator overloading (<< and ==) is used to make printing and comparing parts cleaner and more natural.
The program includes exception handling and safe input methods so it doesn’t crash on bad input.
A simple text menu lets the user interact with the system easily.
Overall, the design focuses on clean OOP structure, safe memory usage, modular code, and practical use of modern C++ features.
