#!/usr/bin/env groovy
s1="PDTR-ABC-Build-WIN"
m= s1 =~ /^PDTR-(.*)/
if(m){
    println "${s1} is valid"
    println m.group(1)
}else{
    println "${s1} is invalid"
}

s2="Trigger-PDTR-ABC-Build-WIN"
m= s2 =~ /^PDTR-.*/
if(m){
    println "${s2} is valid"
}else{
    println "${s2} is invalid"
}