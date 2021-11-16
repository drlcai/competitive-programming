#include <iostream>
#include <vector>
using namespace std;

int main() {
    int b; // B种豆子
    cin >> b;
    vector<int> v(b); // 每种豆子需要V[i]个
    for (int i = 0; i < b; ++i) {
        cin >> v[i];
    }
    int farms;
    cin >> farms; // farmers的个数
    vector<int> farm_mask(farms, 0); // 这个mask很有趣
    for (int f = 0; f < farms; ++f) {
        int types;
        cin >> types;
        for (int t = 0; t < types; ++t) {
            int i;
            cin >> i;
            // 这个mask表，记录了每一个farmer有什么类型的种子
            farm_mask[f] = farm_mask[f] | (1 << (i - 1)); // 第f个farmer，用or改变第i-1位
        }
    }

    int ans_cows = 0;
    // adversarial mask
    // 一种很好的枚举全部子集的方式
    for (int adv_mask = 0; adv_mask < (1 << b); ++adv_mask) {
        bool is_adv = true;
        // 从farmer mask里面一个个去看
        for (int f = 0; f < farms; ++f) {
            // 如果存在一个farmer，不提供任何adversary的种子，同时farmer f是提供种子的（不为0）
            // 那么这个adversary没法这么选，因为adversary只能从farmer中选择
            if ((farm_mask[f] & adv_mask) == 0 && farm_mask[f] != 0) {
                is_adv = false;
                break;
            }
        }
        // 如果这个adversary可以被选择出来，那么就计算牛
        if (is_adv) {
            int cows = 0;
            for (int t = 0; t < b; ++t) {
                // adversary每一个1的位是选择的一种种子，然后用bit op去检查每一位是1还是0
                // 如果是0，那么就加上那个种子对应的数量
                if (((adv_mask >> t) & 1) == 0) {
                    cows += v[t];
                }
            }
            if (ans_cows < cows) {
                ans_cows = cows;
            }
        }
    }

    cout << ans_cows << '\n';
    return 0;
}