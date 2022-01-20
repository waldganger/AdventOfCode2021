use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
    let profondeurs = init_profondeurs("./day1/day1.txt");
    let increased = count_increased_profondeurs(&profondeurs);
    println!("Il y a {} relevés en augmentation.", increased);
}

fn init_profondeurs(path: &str) -> Vec<u32> {
    let file = File::open(path).unwrap();
    let reader = BufReader::new(file);
    let mut profondeurs: Vec<u32> = Vec::new();

    for line in reader.lines() {
        let number: u32 = match line.unwrap().trim().parse() {
            Ok(num) => num,
            Err(_) => panic!("Cannot parse"),
        };
        profondeurs.push(number);
    }
    profondeurs
}

fn count_increased_profondeurs(v: &Vec<u32>) -> u32 {
    let mut prev_prof: u32 = 0;
    let mut counter: u32 = 0;

    for p in v {
        if prev_prof == 0 {
            println!("{} (N/A - no previous measurement)", p);
            prev_prof = *p;
        } else if p > &prev_prof {
            println!("{} (increased)", p);
            counter += 1;
            prev_prof = *p;
        } else {
            println!("{} (decreased)", p);
            prev_prof = *p;
        }
    }
    counter
}
