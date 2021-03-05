use std::io::prelude::*;
use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    io::stdin().read_to_string(&mut buffer)?;
    
    let ans = buffer
        .trim()
        .split("\n")
        .skip(1)
        .map(|line| line.trim().split_whitespace().map(|v| v.parse::<f64>().unwrap()).collect::<Vec<_>>())
        .map(solve)
        .map(|solution| solution.to_string())
        .collect::<Vec<_>>()
        .join("\n");
    
    println!("{}", ans);
    
    return Ok(());
}

fn solve(input: Vec<f64>) -> i32 {
    let n = input[0] + input[1];
    let real = n / 2.0;
    return ((input[0] - real) * 100.0 / real).round() as i32;
}
