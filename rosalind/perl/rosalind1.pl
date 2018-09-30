#!/usr/bin/perl
print "\nsequence:";
my $seq = <STDIN>;
my $numA = ($seq =~s/A/a/g);
my $numC = ($seq =~s/C/a/g);
my $numG = ($seq =~s/G/a/g);
my $numT = ($seq =~s/T/a/g);
print $numA, ' ', $numC, ' ', $numG, ' ', $numT, ' ', "\n";