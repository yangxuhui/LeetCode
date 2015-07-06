// Source: https://leetcode.com/problems/rectangle-area/
// 2015/7/6

// My Solution
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (C <= E || G <= A || D <= F || H <= B) return (C - A) * (D - B) + (G - E) * (H - F);
        int bottom_x = (A > E) ? A : E;
        int bottom_y = (B > F) ? B : F;
        int top_x = (C < G) ? C : G;
        int top_y = (D < H) ? D : H;
        return (C - A) * (D - B) + (G - E) * (H - F) - (top_x - bottom_x) * (top_y - bottom_y);
    }
}; // 32ms

// Reference https://leetcode.com/discuss/39592/simple-solution-using-and-max-updated-again-avoid-overflow
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap_width = min(C, G) > max(A, E) ? min(C, G) - max(A, E) : 0;
        int overlap_height = min(D, H) > max(B, F) ? min(D, H) - max(B, F) : 0;
        return (C - A) * (D - B) - overlap_width * overlap_height + (G - E) * (H - F);
    }
}; // 36ms
