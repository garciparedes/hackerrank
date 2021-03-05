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
        .collect::<Vec<_>>()
        .join("\n");
    
    println!("{}", ans);
    
    return Ok(());
}

fn solve(degrees: Vec<f64>) -> String {
    let minutes = degrees[0] * 60.0 / 360.0;
    let hours = degrees[1] * 12.0 / 360.0;
    if (hours - hours.round() - minutes / 60.0).abs() < 0.00001 {    
        return format!("{:0>2}:{:0>2}", hours as u64, minutes as u64);
    }
    
    let minutes = degrees[1] * 60.0 / 360.0;
    let hours = degrees[0] * 12.0 / 360.0;
    if (hours - hours.round() - minutes / 60.0).abs() < 0.00001 {    
        return format!("{:0>2}:{:0>2}", hours as u64, minutes as u64);
    }
    
    return String::from("ERROR");
}
