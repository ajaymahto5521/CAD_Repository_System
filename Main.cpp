#include <iostream>
#include <memory>
#include <limits>
#include "Repository.h"
#include "Pipe.h"
#include "Valve.h"
#include "Elbow.h"
#include "Flange.h"

using std::cout; using std::cin; using std::endl;

void flushInput() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readInt(const std::string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) return x;
        cout << "Invalid integer. Try again.\n";
        flushInput();
    }
}

double readDouble(const std::string& prompt) {
    double d;
    while (true) {
        cout << prompt;
        if (cin >> d) return d;
        cout << "Invalid number. Try again.\n";
        flushInput();
    }
}

std::string readStringLine(const std::string& prompt) {
    std::string s;
    flushInput();
    cout << prompt;
    getline(cin, s);
    return s;
}

void addPipe(Repository<Part>& repo) {
    int id = readInt("ID: ");
    std::string name = readStringLine("Name: ");
    std::string material = readStringLine("Material: ");
    double diameter = readDouble("Diameter(in cm): ");
    double length = readDouble("Length(in cm): ");
    double thickness = readDouble("Thickness(in cm): ");
    auto p = std::make_shared<Pipe>(id, name, material, diameter, length, thickness);
    repo.add(p);
    cout << "Pipe added.\n";
}

void addValve(Repository<Part>& repo) {
    int id = readInt("ID: ");
    std::string name = readStringLine("Name: ");
    std::string material = readStringLine("Material: ");
    double diameter = readDouble("Diameter(in cm): ");
    cout << "Valve Type (0=Ball,1=Gate,2=Globe,3=Check): ";
    int vt; cin >> vt;
    double pr = readDouble("Pressure rating: ");
    ValveType vtype = static_cast<ValveType>(vt);
    auto v = std::make_shared<Valve>(id, name, material, diameter, vtype, pr);
    repo.add(v);
    cout << "Valve added.\n";
}

void addElbow(Repository<Part>& repo) {
    int id = readInt("ID: ");
    std::string name = readStringLine("Name: ");
    std::string material = readStringLine("Material: ");
    double diameter = readDouble("Diameter(in cm): ");
    double angle = readDouble("Angle (deg): ");
    auto e = std::make_shared<Elbow>(id, name, material, diameter, angle);
    repo.add(e);
    cout << "Elbow added.\n";
}

void addFlange(Repository<Part>& repo) {
    int id = readInt("ID: ");
    std::string name = readStringLine("Name: ");
    std::string material = readStringLine("Material: ");
    double diameter = readDouble("Diameter(in cm): ");
    std::string ftype = readStringLine("Flange type: ");
    int bolts = readInt("Bolt count: ");
    auto f = std::make_shared<Flange>(id, name, material, diameter, ftype, bolts);
    repo.add(f);
    cout << "Flange added.\n";
}

void viewAll(const Repository<Part>& repo) {
    auto list = repo.viewAll();
    if (list.empty()) {
        cout << "No parts stored.\n";
        return;
    }
    for (const auto& p : list) {
        cout << *p << '\n';
    }
}

void searchById(const Repository<Part>& repo) {
    int id = readInt("Enter ID to search: ");
    auto p = repo.findById(id);
    if (p) cout << *p << '\n';
    else cout << "Not found.\n";
}

void searchByName(const Repository<Part>& repo) {
    std::string s = readStringLine("Enter substring for name search: ");
    auto res = repo.findByName(s);
    if (res.empty()) cout << "No matches.\n";
    else for (auto& p : res) cout << *p << '\n';
}

void deleteById(Repository<Part>& repo) {
    int id = readInt("Enter ID to delete: ");
    if (repo.removeById(id)) cout << "Deleted.\n";
    else cout << "Not found.\n";
}

int main() {
    Repository<Part> repo;
    bool running = true;
    while (running) {
        cout << "====<<<<<<<< CAD Parts Repository >>>>>>>>>====\n";
        cout << "1. Add Pipe\n2. Add Valve\n3. Add Elbow\n4. Add Flange\n";
        cout << "5. View all parts\n6. Search by ID\n7. Search by Name\n8. Delete by ID\n9. Count\n0. Exit\nChoose: ";
        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input. Try again.\n";
            flushInput();
            continue;
        }
        try {
            switch (choice) {
            case 1: addPipe(repo); break;
            case 2: addValve(repo); break;
            case 3: addElbow(repo); break;
            case 4: addFlange(repo); break;
            case 5: viewAll(repo); break;
            case 6: searchById(repo); break;
            case 7: searchByName(repo); break;
            case 8: deleteById(repo); break;
            case 9: cout << "Count: " << repo.count() << "\n"; break;
            case 0: running = false; break;
            default: cout << "Unknown option.\n"; break;
            }
        }
        catch (const std::exception& ex) {
            cout << "Error: " << ex.what() << '\n';
        }
        cout << '\n';
    }
    cout << "Bye.\n";
    return 0;
}
