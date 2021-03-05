use std::io::prelude::*;
use std::io;
use std::cmp;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    io::stdin().read_to_string(&mut buffer)?;
    let mut iterable = buffer
        .trim()
        .split("\n");
    
    
    while let Some(line) = iterable.next() {
        let n = line.trim().parse::<usize>().unwrap();
        
        
        let mut matrix = Vec::new();
        for _ in 0..n {
            let line = iterable.next().unwrap();
            let row: Vec<usize> = line.trim().split_whitespace().map(|v| v.parse::<usize>().unwrap()).collect();
            matrix.push(row);
        }
        let ans = solve(matrix);
        
        
        println!("{}", ans.into_iter().map(|v| v.to_string()).collect::<Vec<_>>().join(" "));    

    }
    
    return Ok(());
}

fn solve(matrix: Vec<Vec<usize>>) -> Vec<usize> {
    let n = matrix.len();
    let n_2 = n / 2;
    let mut n_22 = n_2;
    if matrix.len() % 2 == 1 {
        n_22 += 1;
    }
    
    let mut ans = vec![0; n_22];
    for (i, row) in matrix.into_iter().enumerate() {
        for (j, cell) in row.into_iter().enumerate() {
            
            let mut k = 1500;
            if n % 2 == 1 {
                k = cmp::max(
                    (n_2 as i32 - i as i32).abs(), 
                    (n_2 as i32 - j as i32).abs()
                )
            } else {
                let mut tmp = cmp::max((n_2 as i32 - i as i32).abs(), (n_2 as i32 - j as i32).abs());
                if tmp < k {
                    k = tmp;
                }
                
                tmp = cmp::max((n_2 as i32 - i as i32).abs(), ((n_2 - 1) as i32 - j as i32).abs());
                if tmp < k {
                    k = tmp;
                }
                
                tmp = cmp::max(((n_2 - 1) as i32 - i as i32).abs(),  (n_2 as i32 - j as i32).abs());
                if tmp < k {
                    k = tmp;
                }
                
                tmp = cmp::max(((n_2 - 1) as i32 - i as i32).abs(), ((n_2 - 1) as i32 - j as i32).abs());
                if tmp < k {
                    k = tmp;
                }
            }
            ans[k as usize] += cell;       
        }
    }
    return ans;
    
}
