// Thanos Sort
// -----------
// Link: https://codeforces.com/contest/1145/problem/A
// Rating: None

// Completed: Oct. 5, 2019
// By: Ivy Zhang

use std::cmp;
use std::convert::TryInto;
use std::io;

fn main() {
    let mut number_of_numbers = String::new();
    let mut numbers = String::new();

    io::stdin().read_line(&mut number_of_numbers)
        .expect("Failed to read line.");
    
    let number_of_numbers: u32 = number_of_numbers.trim().parse()
        .expect("Expected a number from first line.");
    
    io::stdin().read_line(&mut numbers)
        .expect("Failed to read line");

    let numbers: Vec<i32> = numbers
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let longest: u32 = thanos_sort(numbers).try_into().unwrap();
    println!("{}", longest);
}

fn thanos_sort(numbers: Vec<i32>) -> usize {
    let mut sorted: bool = true;
    let mut index: usize = 1;

    while index < numbers.len().try_into().unwrap() {
        if numbers[index] < numbers[index - 1] {
            sorted = false;
            break;
        }
        index = index + 1;
    } 


    if sorted {
        return numbers.len();
    } else {
        let (left, right) = numbers.split_at(numbers.len()/2);
        return cmp::max(thanos_sort(left.to_vec()), thanos_sort(right.to_vec()));
    }
}
