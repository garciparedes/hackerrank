use std::io::prelude::*;
use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    io::stdin().read_to_string(&mut buffer)?;
    let mut iterable = buffer
        .trim()
        .split("\n");
    
    
    while let Some(line) = iterable.next() {
        if line.trim() == "0" {
            break;
        }
        
        let cups: Vec<_> = iterable
            .next()
            .unwrap()
            .trim()
            .split_whitespace()
            .map(|v| v.parse::<usize>().unwrap())
            .collect();
        
        let mut ans = 0;
        if !cups.is_empty() {
            let maximum = *cups.iter().max().unwrap();
        
            for c in cups {
                ans += maximum - c;
            }
        }
        println!("{}", ans);    

    }
    
    return Ok(());
}

