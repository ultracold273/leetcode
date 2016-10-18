/*
 * LeetCode 127 - Word Ladder
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, 
 * find all shortest transformation sequence(s) from beginWord to endWord, 
 * such that:
 *
 *   1. Only one letter can be changed at a time
 *   2. Each intermediate word must exist in the word list
 *
 * For example,
 *
 *   Given:
 *   beginWord = "hit"
 *   endWord = "cog"
 *   wordList = ["hot","dot","dog","lot","log"]
 *
 *   As one shortest transformation is 
 *          "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 *   Return its length 5.
 *
 * Note:
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 *
 */
