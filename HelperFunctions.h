#pragma once

template<typename DataType>
class TBinaryTree;

template<typename DataType>
class TGraph;

template<typename T>
inline void Print(const T& A) { std::cout << A << std::endl; }

inline bool Max(const int& A, const int& B) { return A > B; }

template<typename T>
inline void PrintTreeNode(TBinaryTree<T>* Node) { Print(Node->Data); }

template<typename T>
inline void PrintGraphNode(TGraph<T>* Node) { Print(Node->Data); }
