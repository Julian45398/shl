#pragma once

#include <vector>
#include <assert.h>

namespace shl {
	template<typename T>
	inline bool isSorted(T* arr, size_t size) {
		for (size_t i = 1; i < size; ++i) {
			if (arr[i] < arr[i - 1]) {
				return false;
			}
		}
		return true;
	}
	template<typename T>
	inline bool isSorted(std::vector<T>& arr) {
		return isSorted(arr.data(), arr.size());
	}
	
	template<typename T>
	inline void reverseArray(T* arr, size_t size) {
		size_t half = size / 2;
		for (size_t i = 0; i < half; ++i) {
			std::swap(&arr[i], &arr[size - i]);
		}
	}
	template<typename T>
	inline void reverseArray(std::vector<T>& arr) {
		reverseArray(arr.data(), arr.size());
	}
	
	template<typename T>
	inline void insertionSort(T* toSort, size_t size) {
		for (size_t i = 1; i < size; ++i) {
			size_t key = toSort[i];
			size_t j = i - 1;

			while (j >= 0 && toSort[j] > key) {
				toSort[j + 1] = toSort[j];
				j = j - 1;
			}
			toSort[j + 1] = key;
		}
	}
	template<typename T>
	inline void insertionSort(std::vector<T>& toSort) {
		insertionSort(toSort.data(), toSort.size());
	}

	template<typename T>
	inline size_t pickPivot(T* toSort, size_t start, size_t end) {
		assert(start < end);
		size_t mid = (end - start) / 2;
		size_t lower = toSort[start] < toSort[end] ? start : end;
		return toSort[mid] < toSort[lower] ? lower : mid;
	}
	template<typename T>
	inline size_t swapAroundPivot(T* toSort, size_t start, size_t end, size_t pivot) {
		assert(start < end);
		assert(pivot <= end);
		assert(start <= pivot);
		constexpr T& value = toSort[pivot];
		std::swap(&toSort[pivot], &toSort[end]);
		size_t lower = end - 1;
		size_t higher = start;
		while (true) {
			for (; start < lower; --lower) {
				if (toSort[lower] < value)
					break;
			}
			for (; higher < end; ++higher) {
				if (value < toSort[higher])
					break;
			}
			if (lower < higher) {
				break;
			}
			std::swap(&toSort[higher], &toSort[lower]);
		}
		std::swap(&toSort[higher], &toSort[end]);
		return higher;
	}
	template<typename T>
	inline void quickSortSlice(T* toSort, size_t start, size_t end) {
		size_t pivot = pickPivot(toSort, start, end);
		pivot = swapAroundPivot(toSort, start, end, pivot);
		if (pivot < end) {
			quickSortSlice(toSort, start, pivot - 1);
			quickSortSlice(toSort, pivot + 1, end);
		}
	}
	template<typename T>
	inline void quickSort(T* toSort, size_t size) {
		quickSortSlice(toSort, 0, size);
	}
	template<typename T>
	inline void quickSort(std::vector<T>& toSort) {
		quickSortSlice(toSort.data(), 0, toSort.size());
	}

	template<typename T>
	inline void bubbleSort(T* toSort, size_t size) {
		for (size_t i = 0; i < size - 1; ++i) {

			bool swapped = false;
			for (size_t j = 0; j < size - i - 1; ++j) {
				if (toSort[j] > toSort[j+1]) {
					std::swap(toSort[j], toSort[j + 1]);
					swapped = true;
				}
			}
			if (!swapped)
				return;
		}
	}
	template<typename T>
	inline void bubbleSort(std::vector<T> toSort) {
		bubbleSort(toSort.data(), toSort.size());
	}
	
}