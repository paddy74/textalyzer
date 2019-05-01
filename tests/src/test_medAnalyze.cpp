#include <iostream>

#include <textalyzer/Analyzer.hpp>


int main()
{
    std::string testStr = "All our submissions from the Microsoft Research Cambridge (MSRC) team this year continue to explore issues in IR from a perspective very close to that of the original Okapi team, working first at City University of London, and then at MSRC. A summary of the contributions by the team, from TRECs 1 to 7 is presented in [3]. In this work, weighting schemes for ad-hoc retrieval were developed, inspired by a probabilistic interpretation of relevance; this lead, for instance, to the successful BM25 weighting function. These weighting schemes were extended to deal with pseudo relevance feedback (blind feedback). Furthermore, the Okapi team participated in most of the early interactive tracks, and also developed iterative relevance feedback strategies for the routing task. Following up on the routing work, TRECs 7–11 submissions dealt principally with the adaptive filtering task; this work is summarised in [5]. Last year MSRC entered only the HARD track, concentrating on the use of the clarification forms [6]. We hoped to make use of the query expansion methods developed for filtering in the context of feedback on snippets in the clarification forms. However, our methods were not very successful. In this year’s TREC we took part in the HARD and WEB tracks. In HARD, we tried some variations on the process of feature selection for query expansion. On the WEB track, we investigated the combination of information from different content fields and from link-based features. Section 3 briefly describes the system we used. Section 4 describes our HARD participation and Section 5 our TREC participation.";

    auto const anlyzPair = textalyzer::Analyzer::medAnalyze(testStr, 2);

    std::cout << "Test: medAnalyze\n----------------\n";
    std::cout << "Number of words: " << anlyzPair.second << std::endl << "[";
    for (auto const & item : anlyzPair.first)
        std::cout << item << ", ";
    std::cout << "]" << std::endl;

    return 0;
}
