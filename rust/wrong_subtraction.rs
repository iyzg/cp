// Wrong Subtraction
// -----------------
// Link: https://codeforces.com/contest/977/problem/A
// Rating: 500

// Completed: Oct. 5, 2019
// By: ivy Zhang

use std::io;

fn main() {
    let mut numbers = String::new();

    io::stdin().read_line(&mut numbers)
        .expect("Failed to read line.");

    let numbers: Vec<u32> = numbers
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let mut number: u32 = numbers[0];
    let times: u32 = numbers[1];
    
    let mut current_time: u32 = 0;

    while current_time < times {
        if number % 10 != 0 {
            number = number - 1
        } else {
            number = number / 10
        }

        current_time = current_time + 1;
    }

    println!("{}", number);
}
