#include <cmath>
// key 以上の値のうち最小の値を返す
// O(logn)

//int binary_search(int key) {
//    int left = -1;  //常に条件を満たさない(0が条件を満たすこともある)
//    int right = 100001;  //常に条件を満たす(100000が条件を満たさないこともある)
//    while (right - left > 1) {
//        int mid = (left + right) / 2;
//        if (mid > key)
//            right = mid;
//        else
//            left = mid;
//    }
//    return right;
//}
//
bool isOk(int key) {
    return true;
}

int binary_search(int ok, int ng) {
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOk(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}
