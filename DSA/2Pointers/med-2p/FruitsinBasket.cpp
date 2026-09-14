#include <unordered_map>
#include <vector>
using namespace std;

int FruitsinBasket(vector<int> &arr)
{
    int n = arr.size();
    int left = 0;
    unordered_map<int, int> fruitCount;
    int right = 0;
    int basketCount = 2;
    int maxFruits = 0;
    int cnt = 0;
    while (right < n)
    {
        if (fruitCount.find(arr[right]) != fruitCount.end())
        {
            fruitCount[arr[right]]++;
        }
        else
        {
            if (fruitCount.size() < basketCount)
            {
                fruitCount[arr[right]] = 1;
            }
            else
            {
                while (fruitCount.size() >= basketCount)
                {
                    fruitCount[arr[left]]--;
                    cnt--;
                    if (fruitCount[arr[left]] == 0)
                    {
                        fruitCount.erase(arr[left]);
                    }
                    left++;
                }
                fruitCount[arr[right]] = 1;
            }
        }
        cnt++;
        right++;
        maxFruits = max(maxFruits, cnt);
    }
    return maxFruits;
}