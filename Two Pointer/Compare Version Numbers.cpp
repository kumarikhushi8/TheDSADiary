/*
Problem: Compare Version Numbers
LeetCode: 165

Approach:
- Use two pointers to traverse both version strings.
- Parse each revision number between two dots.
- Compare the corresponding revision numbers.
- If one version has fewer remaining revisions, treat the missing
  revisions as 0.
- Continue until both strings are completely processed.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/
