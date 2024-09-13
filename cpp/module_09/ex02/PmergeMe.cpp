/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:44:16 by daraz             #+#    #+#             */
/*   Updated: 2024/09/13 16:09:59 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> & input, int size) : _containerVector(input), _containerDeque(input.begin(), input.end()), _size(size) {
	this->_sortVector();
	this->_sortDeque();
}

PmergeMe::PmergeMe(PmergeMe const &src) : _size(src._size) {
	this->_containerVector = src._containerVector;
	this->_containerDeque = src._containerDeque;
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &	PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		this->_containerVector = rhs._containerVector;
		this->_containerDeque = rhs._containerDeque;
	}
	return *this;
}

void PmergeMe::_sortVector() {
    clock_t start = clock();

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < this->_containerVector.size(); i += 2) {
        if (i + 1 < this->_containerVector.size()) {
            if (this->_containerVector[i] < this->_containerVector[i + 1]) {
                pairs.push_back(std::make_pair(this->_containerVector[i], this->_containerVector[i + 1]));
            } else {
                pairs.push_back(std::make_pair(this->_containerVector[i + 1], this->_containerVector[i]));
            }
        } else {
            pairs.push_back(std::make_pair(this->_containerVector[i], this->_containerVector[i]));
        }
    }
    std::vector<int> sorted_seq;
    sorted_seq.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i) {
        sorted_seq.push_back(pairs[i].second);
    }
    for (size_t i = 1; i < sorted_seq.size(); ++i) {
        int key = sorted_seq[i];
        size_t j = i;
        while (j > 0 && sorted_seq[j - 1] > key) {
            sorted_seq[j] = sorted_seq[j - 1];
            --j;
        }
        sorted_seq[j] = key;
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        int smaller = pairs[i].first;
        if (std::find(sorted_seq.begin(), sorted_seq.end(), smaller) == sorted_seq.end()) {
            std::vector<int>::iterator it = std::lower_bound(sorted_seq.begin(), sorted_seq.end(), smaller);
            sorted_seq.insert(it, smaller);
        }
    }
    std::cout << "After: ";
    for (std::vector<int>::iterator it = sorted_seq.begin(); it != sorted_seq.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << this->_size << " elements with std::vector<int> : " << duration << " us" << std::endl;
}


void PmergeMe::_sortDeque() {
    clock_t start = clock();
	
    std::deque<std::pair<int, int> > pairs;
    std::deque<int>::iterator it = this->_containerDeque.begin();

    for (size_t i = 0; i < this->_containerDeque.size(); i += 2) {
        if (i + 1 < this->_containerDeque.size()) {
            if (*it < *(it + 1)) {
                pairs.push_back(std::make_pair(*it, *(it + 1)));
            } else {
                pairs.push_back(std::make_pair(*(it + 1), *it));
            }
            it += 2;
        } else {
            pairs.push_back(std::make_pair(*it, *it));
            it++;
        }
    }

    std::deque<int> sorted_seq;
    sorted_seq.insert(sorted_seq.end(), pairs.size(), 0);
    for (size_t i = 0; i < pairs.size(); ++i) {
        sorted_seq[i] = pairs[i].second;
    }

    for (size_t i = 1; i < sorted_seq.size(); ++i) {
        int key = sorted_seq[i];
        size_t j = i;
        while (j > 0 && sorted_seq[j - 1] > key) {
            sorted_seq[j] = sorted_seq[j - 1];
            --j;
        }
        sorted_seq[j] = key;
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        int smaller = pairs[i].first;
        if (std::find(sorted_seq.begin(), sorted_seq.end(), smaller) == sorted_seq.end()) {
            std::deque<int>::iterator it = std::lower_bound(sorted_seq.begin(), sorted_seq.end(), smaller);
            sorted_seq.insert(it, smaller);
        }
    }
    /* std::cout << "After: ";
    for (std::deque<int>::iterator it = sorted_seq.begin(); it != sorted_seq.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl; */
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << this->_size << " elements with std::deque<int> : " << duration << " us" << std::endl;
}
