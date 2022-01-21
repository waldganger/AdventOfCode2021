use std::fs::File;
use std::io::{BufRead, BufReader};

pub fn day1_ex1() {
  let profondeurs = init_profondeurs("./day1/day1.txt");
  let increased = count_increased_profondeurs(&profondeurs);
  println!("Il y a {} relevés en augmentation.", increased);
}

pub fn day1_ex2() {
  let profondeurs = init_profondeurs("./day1/day1.txt");
  let sum_of_three = make_window(0, 3, &profondeurs);
  let increased3 = compare_increased_profondeurs(&sum_of_three);
  println!("Il y a {} relevés en augmentation.", increased3);
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

fn compare_increased_profondeurs(v_sums: &Vec<u32>) -> u32 {
  let mut prev_win_sum: u32 = 0;
  let mut increases_counter: u32 = 0;

  for i in 0..v_sums.len() {
    if prev_win_sum == 0 {
      println!("{} (N/A - no previous measurement)", v_sums[i]);
      prev_win_sum = v_sums[i];
    } else if v_sums[i] > prev_win_sum {
      println!("{} (increased)", v_sums[i]);
      increases_counter += 1;
      prev_win_sum = v_sums[i];
    } else {
      println!("{} (decreased)", v_sums[i]);
      prev_win_sum = v_sums[i];
    }
  }
  increases_counter
}

fn make_window(start: usize, offset: usize, profondeurs: &Vec<u32>) -> Vec<u32> {
  let max_vector_index = profondeurs.len() - (profondeurs.len() % offset);
  let mut sommes: Vec<u32> = vec![];
  let mut si: u32 = 0;

  for i in start..max_vector_index {
    for j in 0..offset {
      si += profondeurs[i + j];
    }
    sommes.push(si);
    si = 0;
  }
  sommes
}
