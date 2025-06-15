# Leetcode-926.-Flip-String-to-Monotone-Increasing
# 🚀 Minimum Flips to Make String Monotone Increasing

## 🧩 Problem Statement

Given a binary string `s`, we want to make it **monotone increasing** by flipping some characters. A string is monotone increasing if it consists of some number of `'0'`s (possibly none), followed by some number of `'1'`s (also possibly none).

🔄 Each flip can change a `'0'` to `'1'` or a `'1'` to `'0'`.

🧠 **Goal:** Minimize the number of flips needed to make the string monotone increasing.

---

## 💡 Approaches Overview

### 🔁 1. Pure Recursion (Top-down without memoization)

* We explore every index and every possible previous value ('0' or '1').
* At each step, we decide whether to flip or not.
* ❌ Very inefficient due to repeated states and no caching.

**Time Complexity:** Exponential (O(2^n))
**Space Complexity:** O(n) (recursion stack)

---

### 🧠 2. Top-Down Recursion with Memoization (DP)

* Same logic as pure recursion, but stores results of subproblems.
* Uses a 2D `dp[i][prev]` array to remember states.

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

### 📉 3. Bottom-Up DP with Array

* Iteratively compute minimum flips up to each index.
* Uses a `dp[i]` array to store the min flips needed up to `i`.
* Tracks the number of `1`s seen so far.

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

### 🧪 4. Optimized DP (Constant Space)

* Reduces DP to just two variables: `prev` and `now`.
* Also tracks the number of `1`s seen so far.
* Most efficient approach in both time and space.

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

## 🧮 Time and Space Complexity Comparison

| Approach                | Time     | Space    |
| ----------------------- | -------- | -------- |
| Pure Recursion          | O(2^n)   | O(n)     |
| Recursion with Memo     | O(n)     | O(n)     |
| Bottom-Up DP (Array)    | O(n)     | O(n)     |
| **Optimized DP (Best)** | **O(n)** | **O(1)** |

---

## 📌 Example

Input: `s = "010110"`

Step-by-step:

* We aim to change this to a format like `000111` with minimum flips.
* A possible solution: flip the second `'1'` and the last `'0'` → result: `001111` → 2 flips.

✅ Output: `2`

---

## ✍️ Author

**Ridham Garg**
🎓 B.Tech Computer Engineering, Thapar University, Patiala
🆔 Roll Number: 102203014

---

## 🎉 Conclusion

This problem demonstrates multiple levels of optimization:

* From brute-force recursion 🚫
* To memoization and classic bottom-up DP ⚙️
* To space-optimized constant memory DP 🧠🔥

The final optimized approach provides a clean and efficient solution suitable for real-world inputs. 🌟
