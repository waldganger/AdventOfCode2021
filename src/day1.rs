use std::fs::File;
use std::io::{BufRead, BufReader};

pub fn day1_ex1() {
  let profondeurs = init_profondeurs("./day1/day1.txt");
  let increased = count_increased_profondeurs(&profondeurs);
  println!("Il y a {} relevés en augmentation.", increased);
}

pub fn day1_ex2() {
  let profondeurs = init_profondeurs("./day1/day1.txt");
  window_slider(&profondeurs);
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

fn window_slider(profondeurs: &Vec<u32>) {
  let sommes_a: Vec<u32> = make_window(2, 3, profondeurs);
  for p in &sommes_a {
    // println!("{}", p);
  }
  println!("Taille de sommesA est {}:", &sommes_a.len());
}

fn make_window(start: usize, offset: u32, profondeurs: &Vec<u32>) -> Vec<u32> {
  let len = profondeurs.len();
  let mut sommes: Vec<u32> = vec![];
  let mut si: u32 = 0;
  let mut offset_counter: u32 = 0;

  for i in start..len {
    if offset_counter < offset {
      si += profondeurs[i];
      offset_counter += 1;

      // println!(
      //   "valeur {} (offset_counter : {})",
      //   profondeurs[i], offset_counter
      // );
    } else {
      sommes.push(si);
      offset_counter = 0;
      println!("{} push {} (offset_counter : {})", i, si, offset_counter);
      offset_counter = 1;
      si = profondeurs[i];
    }
  }
  sommes
}
