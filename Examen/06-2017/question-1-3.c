int v(int a[3]) {
  int multiplicateur = 1;
  int valeur = 0;

  for(int i = 2; i >= 0; i--) {
    valeur += a[i] * multiplicateur;
    multiplicateur *= 10;
  }

  return valeur;
}
