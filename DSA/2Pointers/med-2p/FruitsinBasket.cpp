#include <unordered_map>
#include <vector>
using namespace std;

int FruitsinBasket(vector<int> &arr) // Time Complexity: O(n)  Space Complexity: O(1)
{
    int n = arr.size();
    int left = 0;
    unordered_map<int, int> fruitCount;
    int right = 0;
    int maxFruits = 0;
    while (right < n)
    {
        if (fruitCount.find(arr[right]) != fruitCount.end())
        {
            fruitCount[arr[right]]++;
        }
        else
        {
            if (fruitCount.size() < 2)
            {
                fruitCount[arr[right]] = 1;
            }
            else
            {
                while (fruitCount.size() >= 2)
                {
                    fruitCount[arr[left]]--;
                    if (fruitCount[arr[left]] == 0)
                    {
                        fruitCount.erase(arr[left]);
                    }
                    left++;
                }
                fruitCount[arr[right]] = 1;
            }
        }
        right++;
        maxFruits = max(maxFruits, right - left + 1);
    }
    return maxFruits;
}