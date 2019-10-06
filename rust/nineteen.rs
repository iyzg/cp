// Nineteen
// --------
// Link: https://codeforces.com/contest/393/problem/A
// Rating: None

// Completed: Oct. 5, 2019
// By: Ivy Zhang

use std::cmp;
use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input)
        .expect("Failed to read line");

    let mut number_of_n: u32 = 0;
    let mut number_of_i: u32 = 0;
    let mut number_of_t: u32 = 0;
    let mut number_of_e: u32 = 0;

    for char in input.chars() {
        if char == 'n' {
            number_of_n = number_of_n + 1;
        } else if char == 'i' {
            number_of_i = number_of_i + 1;
        } else if char == 't' {
            number_of_t = number_of_t + 1;
        } else if char == 'e' {
            number_of_e = number_of_e + 1;
        }
    }

    if number_of_n % 2 == 1 {
        number_of_n = number_of_n + (number_of_n / 2) - 1;
    } else {
        number_of_n = (number_of_n - 1) + (number_of_n - 1)/2 -1;
    }
    
    println!("{}", cmp::min(cmp::min(number_of_n/3, number_of_i), cmp::min(number_of_t, number_of_e/3)))
}
