use std::io::prelude::*;
use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    io::stdin().read_to_string(&mut buffer)?;
    
    let ans = buffer
        .trim()
        .split("\n")
        .skip(1)
        .map(|line| line.trim())
        .map(solve)
        .map(|solution| solution.to_string())
        .collect::<Vec<_>>()
        .join("\n");
    
    println!("{}", ans);
    
    return Ok(());
}

fn solve(input: &str) -> i32 {
    let mut ans = 0;
    let colors: Vec<_> = input.chars().collect();
    for i in (0..colors.len()).step_by(2) {
        if colors[i] == colors[i + 1] {
            ans += 1;
        }
        ans += 1;
    }
    return ans;
}
