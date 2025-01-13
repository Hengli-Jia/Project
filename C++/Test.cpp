#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Toy {
   string type;
   string color;
};

int main() {
   vector<Toy> toyList(3);
   int i;

   toyList.at(0).type = "plane";
   toyList.at(0).color = "red";
   toyList.at(1).type = "bear";
   toyList.at(1).color = "pink";
   toyList.at(2).type = "bike";
   toyList.at(2).color = "brown";

   for (i = 0; i < toyList.size(); ++i) {
      cout << toyList.at(i).type << endl;
   }

   return 0;
}