// Pages
// -----
// Link: https://codeforces.com/contest/399/problem/A
// Rating: None

// Completed: Oct. 6, 2019
// By: Ivy Zhang


// To be optimized: 2 lines for the printing of << and >> and then just print with a for loop, this
// was really bad lol 

use std::io;
use std::io::Write;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input)
        .expect("Couldn't read line.");

    let input: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let number_of_pages: i32 = input[0];
    let current_page: i32 = input[1];
    let range_of_pages: i32 = input[2];

    let lower_bound = {
        if current_page - range_of_pages <= 0 {
            1
        } else {
            current_page - range_of_pages
        }
    };

    let higher_bound = {
        if current_page + range_of_pages > number_of_pages {
            number_of_pages
        } else {
            current_page + range_of_pages
        }
    };

    if higher_bound != number_of_pages && lower_bound != 1 {
        print!("<< ");
        io::stdout().flush().unwrap();
        for page in lower_bound..higher_bound+1 {
            if page == current_page {
                print!("({}) ", page);
                io::stdout().flush().unwrap();
            } else {
                print!("{} ", page);
                io::stdout().flush().unwrap();
            }
        }
        print!(">>");
        io::stdout().flush().unwrap();
    } else if higher_bound == number_of_pages && lower_bound != 1 {
        print!("<< ");
        io::stdout().flush().unwrap();
        for page in lower_bound..higher_bound+1 {
            if page == current_page {
                print!("({}) ", page);
                io::stdout().flush().unwrap();
            } else {
                print!("{} ", page);
                io::stdout().flush().unwrap();
            }
        }
    } else if higher_bound == number_of_pages && lower_bound == 1 {
        for page in lower_bound..higher_bound+1 {
            if page == current_page {
                print!("({}) ", page);
                io::stdout().flush().unwrap();
            } else {
                print!("{} ", page);
                io::stdout().flush().unwrap();
            }
        }
    } else if higher_bound != number_of_pages && lower_bound == 1 {
        for page in lower_bound..higher_bound+1 {
            if page == current_page {
                print!("({}) ", page);
                io::stdout().flush().unwrap();
            } else {
                print!("{} ", page);
                io::stdout().flush().unwrap();
            }
        }
        print!(">>");
        io::stdout().flush().unwrap();
    }
}
