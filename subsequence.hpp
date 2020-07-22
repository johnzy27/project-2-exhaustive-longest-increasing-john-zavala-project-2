///////////////////////////////////////////////////////////////////////////////
// subsequence.hpp
//
// An exhaustive optimization algorithm for solving 
// the longest increasing subsequence problem.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cassert>
#include <random>
#include <string>
#include <sstream>
#include <vector>
#include "timer.hpp"

using namespace std;

using sequence = std::vector<int>;

// Convert a sequence into a human-readable string useful for pretty-printing
// or debugging.
std::string sequence_to_string(const sequence& seq) {
  std::stringstream ss;
  ss << "[";
  bool first = true;
  for (auto& x : seq) {
    if (!first) {
      ss << ", ";
    }
    ss << x;
    first = false;
  }
  ss << "]";
  return ss.str();
}

// Generate a pseudorandom sequence of the given size, using the given
// seed, where all elements are in the range [0, max_element]. max_element
// must be non-negative.
sequence random_sequence(size_t size, unsigned seed, int max_element) {

    assert(max_element >= 0);

    sequence result;

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dist(0, max_element);

    for (size_t i = 0; i < size; ++i) {
        result.push_back(dist(gen));
    }

    return result;
}

bool is_increasing(const sequence& A) 
{ 
    //setting my boolean variable = true
    bool increasingOrder = true;
  for (size_t i = 1; i < A.size(); ++i) 
  {
      // TODO
      // write the test to check if A[i-1] and A[i] are
      // in increasing order
      // if not, you need to write what needs to be done

    
      
      //checking if A[i-1] is greater than or equal to A[i]
      if (A[i - 1] >= A[i])
      {
          //if the above condition is satisfied then it will set our boolean variable = to false.
          increasingOrder = false;
      }
      
  }
  //returns true or false
  return increasingOrder;
}

sequence longest_increasing_powerset(const sequence& A) {
    //setting my timer 
    Timer timer;

    const size_t n =A.size();
   
  //outputing the array size 
  cout << "A.SIZE() = " << A.size() << endl;

  sequence best;
  std::vector<size_t> stack(n+1, 0);
  size_t k = 0;
  while (true) 
  {

    if (stack[k] < n) {
      stack[k+1] = stack[k] + 1;
      ++k;
    } else {
      stack[k-1]++;
      k--;
    }

    if (k == 0) {
      break;
    }

    sequence candidate;
    for (size_t i = 1; i <= k; ++i) 
    {
      candidate.push_back(A[stack[i]-1]);
    }
   // TODO
      // write the if statement to test whether candidate determines
      // an increasing sequence AND has a size larger than the size
      // of the current best
      // if both conditions are satisfied, then stored candidate in best


    //checking to see if my sequence is increasing 
    if (is_increasing(candidate))
    {
        //checking to see if my canidate size > best size 
        if (candidate.size() > best.size())
        {
            //if the above condition is satisfied then it stores candidate into best
            best = candidate; 
        }
    }
   }

  //timer variable for time elapsed
  double elapsed = timer.elapsed();
  //outputing how long it took
  cout << "Elapsed time in seconds: " << elapsed << endl;

  //returning best 
  return best;
}
