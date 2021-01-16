// first sol
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int total = 0;
    void findEmployee(vector<Employee*> p, int id) {
        for(int i = 0; i < p.size(); i++) {
            if(p[i]->id == id) {
                total+=p[i]->importance;
                for(int j=0; j < p[i]->subordinates.size(); j++) {
                    findEmployee(p, p[i]->subordinates[j]);
                }
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        findEmployee(employees, id);
        return total;
    }
};


// second sol
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    map<int, Employee*> emp;
    int dfs(int id) {
        Employee* curr = emp[id];
        int total = curr->importance;
        for(int sub: curr->subordinates) {
           total += dfs(sub);

        }
        return total;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e: employees) {
            emp[e->id] = e;
        }
        return dfs(id);
    }
};
