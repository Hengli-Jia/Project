/**~*~*~* 
 Specification file for the College class
===========================================
Name: Hengli Jia
*~*/

#ifndef COLLEGE_H
#define COLLEGE_H

#include<string>

using std::string;

class College
{
    private:
        string code;
        string name;
        int rank;
        int cost;

    public:
        //constructors
        College();
        College(int, string, string, int);

        //setters
        void setCode(string cd){ code = cd;}
        void setName(string nm){ name = nm;}
        void setRank(int rk){ rank = rk;}
        void setCost(int cs){ cost = cs;}

        //getters
        string getCode() const {return code;}
        string getName() const {return name;}
        int getRank() const {return rank;}
        int getCost() const {return cost;}

        //other functions
        void hDdisplay()const;
        void vDisplay()const;
        
       // overloaded operators
        /* Write your code here to declare/define the following overloaded operators:
            - the stream insertion operator ( << )
            - the relational operators (<, >, == ) 
        */
        friend std::ostream& operator<<(std::ostream& lhs, const College& rhs); 

        bool operator< (const College& rhs) const; // less than operator
        bool operator> (const College& rhs) const; // greater than operator
        bool operator== (const College& rhs) const; // equal to operator
    
};

#endif
