#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Solution {
public:

    class Node {
    public:
        int l1 = -1;
        int l2 = -1;
        int p1 = 0;
        int p2 = 0;

        //list<int> TopList;
        //list<int> LowList;
        //list<int> List;
        vector<int> Tops = { 0, 0 };

        void Reset()
        {
            l1 = -1;
            l2 = -1;
            p1 = 0;
            p2 = 0;
        }

        void SetTop(int p)
        {
            if (l2 != -1 && p2 < p - l2)
            {
                if (p2 > 0)
                    p2 = p - l2;
            }
            if (l1 != -1 && p1 < p - l1)
            {
                if (p1 > 0)
                {
                    if (Tops[0] < p1)
                    {
                        Tops[1] = Tops[0];
                        Tops[0] = p1;
                    }
                }
                if (p2 > 0)
                {
                    if (Tops[0] < p2)
                    {
                        Tops[1] = Tops[0];
                        Tops[0] = p2;
                    }
                }

                p1 = p - l1;
                p2 = 0;
            }
        }

        void SetLow(int p)
        {
            if (l1 == -1 || l1 > p)
            {
                l1 = p;
                l2 = -1;
            }
            else if (l2 == -1 || l2 > p)
            {
                l2 = p;
            }
        }

        int Max()
        {

        }
    };

    int prev = -1;
    char up = 0;

    Node node;

    int maxProfit(vector<int>& prices) {
        int size = (int)prices.size();

        prev = prices[0];
        for (int i = 1; i < size; ++i) {
            if (prev < prices[i])
            {
                if (!up)
                {
                    node.SetLow(prev);
                }

                if (i == size - 1)
                {
                    node.SetTop(prices[i]);
                }

                up = true;
            }
            else if (prev > prices[i])
            {
                if (up)
                {
                    node.SetTop(prev);
                }

                up = false;
            }

            prev = prices[i];
        }

        return 0;
    }
};

string ArrayToString(const vector<int>& input)
{
    string output = "";
    char buffer[16] = "";

    for (int i = 0; i < input.size(); ++i)
    {
        if (i != 0)
            output += ", ";

        _itoa_s(input[i], buffer, 10);
        output += buffer;
    }

    return output;
}

int main()
{
    Solution s;

    vector<int> a = { 0,1,4,1,4/*,3,1,3,3,5,4,8,3,1,4,10,1,4,2,4,3,1,3,3,5,4,8,3,2,4,10*/ };
    //vector<int> a = { 3,3,5,0,0,3,1,4 };
    int profit = s.maxProfit(a);

    std::cout << "Max:" << profit << "\n";

    return 0;
}
